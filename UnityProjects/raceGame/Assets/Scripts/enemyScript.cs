using UnityEngine;
using System.Collections;
using System.Net.Sockets;

public class enemyScript : MonoBehaviour
{
    private float v;
    private float[] EnemyVs =
    {
        0f,
        0.05f,
        0.1f,
        0.15f,
        0.2f
    };
	// Use this for initialization
	void Start ()
	{
	    v = EnemyVs[Random.Range(0, 5)];
	}

	// Update is called once per frame
	void Update () {
		transform.Translate(new Vector3(0, 0, v));
		if (transform.position.z < Camera.main.transform.position.z)
		{
			Destroy(gameObject);
		}
	}
}
