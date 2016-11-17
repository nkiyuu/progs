using UnityEngine;
using System.Collections;
using System.Net.Mime;
using UnityEngine.UI;

public class EnemyBulletScipt : MonoBehaviour {

    public GameObject Player;
    private Vector3 playerDirection;
	public PlayerScripts PlayerScripts;

	// Use this for initialization
	void Start () {
	    Destroy(this.gameObject, 8);
	    playerDirection = transform.position - Player.transform.position;
	}
	
	// Update is called once per frame
	void Update () {
	    //プレイヤーのほうに飛んでくる
		transform.position -= playerDirection * 0.01f ;

		//プレイヤーの後ろに来たら弾は消える
		if (Player.transform.position.z - transform.position.z > 5)
		{
			Destroy(this.gameObject);
		}
	}

	void OnTriggerEnter(Collider cl)
	{
		//弾が敵に当たったとき
		if (cl.tag == "Player")
		{
			PlayerScripts.SendMessage("DecreaseHP");
		}
	}
}
