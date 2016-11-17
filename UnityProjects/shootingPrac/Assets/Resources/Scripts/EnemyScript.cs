using UnityEngine;
using System.Collections;

public class EnemyScript : MonoBehaviour
{

    public GameObject Player;
	public PlayerScripts PlayerScripts;
    public GameObject Bullet;
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
	    if (Random.Range(0, 10) == 1)
	    {
	        GameObject bul = Instantiate(Bullet,
	            new Vector3(transform.position.x, transform.position.y, transform.position.z),
	            Quaternion.identity) as GameObject;
	        EnemyBulletScipt enemyBulletScipt = bul.GetComponent<EnemyBulletScipt>();
	        enemyBulletScipt.Player = Player;
		    enemyBulletScipt.PlayerScripts = PlayerScripts;
	    }

	    if (Player.transform.position.z - transform.position.z > 20)
	    {
	        Destroy();
	    }
	}

    void Destroy()
    {
        Destroy(this.gameObject);
    }
}
