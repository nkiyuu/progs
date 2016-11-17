using UnityEngine;
using System.Collections;

public class StartObjScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    void OnTriggerEnter(Collider co)
    {
        if (co.tag == "Ball")
        {
            Rigidbody BallRd = co.gameObject.GetComponent<Rigidbody>();
            BallRd.AddForce(3000f, 100f, 0);
        }
    }
}
