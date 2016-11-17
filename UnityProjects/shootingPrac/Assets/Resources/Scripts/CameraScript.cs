using System;
using UnityEngine;
using System.Collections;
using Random = UnityEngine.Random;

public class CameraScript : MonoBehaviour
{
    //カメラ追従用の変数
    public GameObject Player;
    private Vector3 diff;

    //敵をランダムで呼ぶための変数
    public GameObject EnemyObj;
    private float EnemyAppearDist = 20f;
    private float AppearZ = 1;
    //敵用のスクリプトとか

	// Use this for initialization
	void Start ()
	{
	    //カメラとプレイヤーの相対位置
	    diff = Player.transform.position - transform.position;
	    AppearZ = transform.position.z;
	    transform.position = Player.transform.position - diff;
	}
	
	// Update is called once per frame
	void Update ()
	{
	    //プレイヤーを追従
	    //transform.position = Player.transform.position - diff;
	    transform.position = new Vector3(0, 1.2f, Player.transform.position.z - diff.z);

	    //一定時間で敵をランダムで発生させる
	    if (transform.position.z > AppearZ  )
	    {
	        Debug.Log("create");
	        CreateEnemy();
	    }
	}

    void CreateEnemy()
    {
        AppearZ += EnemyAppearDist;
        GameObject enemy = Instantiate(EnemyObj, new Vector3(Random.Range(-20, 21), Random.Range(-10, 11), transform.position.z + 40), Quaternion.identity) as GameObject;
        EnemyScript es = enemy.GetComponent<EnemyScript>();
        es.Player = Player;
        es.PlayerScripts = Player.GetComponent<PlayerScripts>();
        es.PlayerScripts = Player.GetComponent<PlayerScripts>();
        es.Bullet = Resources.Load<GameObject>("Prefabs/EnemyTorch");
    }
}
