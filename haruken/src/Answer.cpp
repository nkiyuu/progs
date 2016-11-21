//------------------------------------------------------------------------------
/// @file
/// @author   ハル研究所プログラミングコンテスト実行委員会
///
/// @copyright  Copyright (c) 2016 HAL Laboratory, Inc.
/// @attention  このファイルの利用は、同梱のREADMEにある
///             利用条件に従ってください
//------------------------------------------------------------------------------

#include "Answer.hpp"
#include <iostream>
#include <vector>
#include <math.h>
#include <complex>
using namespace std;

typedef double D;      // 座標値の型。doubleかlong doubleを想定
typedef complex<D> P;  // Point
typedef pair<P, P> L;  // Line
typedef vector<P> VP;
typedef pair<P, D> C; // circle
typedef vector<C> VC;
const D EPS = 1e-9;    // 許容誤差。問題によって変える
#define X real()
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
D dot(P a, P b) {
    return (conj(a)*b).X;
}

// 点pの直線aへの射影点を返す
P proj(P a1, P a2, P p) {
    return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pから円aへの接線の接点
VP tangentPoints(P a, D ar, P p) {
    VP ps;
    D sin = ar / abs(p-a);
    if (!LE(sin, 1)) return ps;  // ここでNaNも弾かれる
    D t = M_PI_2 - asin(min(sin, 1.0));
    ps.push_back(                 a + (p-a)*polar(sin, t));
    if (!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));
    return ps;
}

// 直線と円の交点を返す
VP crosspointLC(P a1, P a2, P c, D r) {
    VP ps;
    P ft = proj(a1, a2, c);
    if (!GE(r*r, norm(ft-c))) return ps;

    P dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
    ps.push_back(ft + dir);
    if (!EQ(r*r, norm(ft-c))) ps.push_back(ft - dir);
    return ps;
}

P getShootPoint(P shipPos, VC asteroids){
    VP contactFromShip = {} ;
    int destroyNumber = 0, destroyNumberLast = 0;
    P shootPoint;
    for(unsigned int i = 0; i < asteroids.size(); i++){
        contactFromShip = tangentPoints(asteroids[i].first, asteroids[i].second, shipPos); // ある隕石との接点の集合を求める
        for(unsigned int j = 0; j < contactFromShip.size(); j++) {
            destroyNumber = 0;
            for (unsigned int k = 0; k < asteroids.size(); k++) {
                destroyNumber += crosspointLC(shipPos, contactFromShip[j], asteroids[k].first,
                                              asteroids[k].second).size();
            }
            if(destroyNumber> destroyNumberLast){
                destroyNumberLast = destroyNumber;
                shootPoint = contactFromShip[j];
            }
        }
    }
    return shootPoint;
}

/// プロコン問題環境を表します。
namespace hpc {

//------------------------------------------------------------------------------
/// Answer クラスのコンストラクタです。
///
/// @note ここにインスタンス生成時の処理を書くことができますが、何も書かなくても構いません。
    Answer::Answer() {
    }

//------------------------------------------------------------------------------
/// Answer クラスのデストラクタです。
///
/// @note ここにインスタンス破棄時の処理を書くことができますが、何も書かなくても構いません。
    Answer::~Answer() {
    }

//------------------------------------------------------------------------------
/// 各ステージ開始時に呼び出されます。
///
/// @note ここで、各ステージに対して初期処理を行うことができます。
///
    VC asteroids = {};
/// @param[in] aStage 現在のステージ。
    void Answer::init(const Stage &aStage) {
    }

//------------------------------------------------------------------------------
/// 各ターンでの行動を返します。
///
/// @param[in] aStage 現在ステージの情報。
///
/// @return これから行う行動を表す Action クラス。
    Action Answer::getNextAction(const Stage &aStage) {
        // レーザーが発射できるときは、レーザーを発射します。
        // レーザーが発射できないときは、移動します。
        if (aStage.ship().canShoot()) {
            asteroids = {};
            // 幾何ライブラリに合わせてステージを読み込む
            for(int i = 0; i < aStage.asteroidCount(); i++){
                if(aStage.asteroid(i).exists()) {
                    asteroids.push_back(
                            C(P(aStage.asteroid(i).pos().x, aStage.asteroid(i).pos().y), aStage.asteroid(i).radius()));
                }
            }
            // 発射目標にする小惑星を決定します。
            Vector2 targetShootPos;
            P shootPos = getShootPoint(P(aStage.ship().pos().x, aStage.ship().pos().x), asteroids);
            targetShootPos= Vector2((float)shootPos.real(), (float)shootPos.imag());
            return Action::Shoot(targetShootPos);
        } else {
            // 移動目標にする小惑星を決定します。
            Vector2 targetMovePos;
            for (int i = aStage.asteroidCount() - 1; i >= 0; --i) {
                if (aStage.asteroid(i).exists()) {
                    targetMovePos = aStage.asteroid(i).pos();
                    break;
                }
            }
            return Action::Move(targetMovePos);
        }
    }

//------------------------------------------------------------------------------
/// 各ステージ終了時に呼び出されます。
///
/// @param[in] aStage 現在ステージの情報。
///
/// @note ここにステージ終了時の処理を書くことができますが、何も書かなくても構いません。
    void Answer::finalize(const Stage &aStage) {
    }

} // namespace
// EOF
