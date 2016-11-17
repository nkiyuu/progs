using UnityEngine;
using System.Collections;
using System.Xml;

public class BulletScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
        Destroy(this.gameObject, 5);
	}
	
	// Update is called once per frame
	void Update () {
	    transform.position += new Vector3(0, 0, 2f);
	}

	void OnTriggerEnter(Collider cl)
	{
		if (cl.tag == "Enemy")
		{
			Debug.Log("hit!!");
			EnemyScript clScript = cl.GetComponent<EnemyScript>();
			clScript.SendMessage("Destroy");
		}
	}
}
