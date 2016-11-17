using UnityEngine;
using System.Collections;

public class PinScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
	
	}

    void FixedUpdate()
    {
        if (this.rigidbody.velocity.x > 0.5 || this.rigidbody.velocity.z > 0.5)
            DelayDestroy();
            //Destroy(this.gameObject);
        }

    void DestroyMethod()
    {
        Destroy(this.gameObject);
    }

    void DelayDestroy()
    {
        Invoke("DestroyMethod", 1.5f);
    }
}
