using UnityEngine;
using System.Collections;

public class BowlScript : MonoBehaviour
{

	public float speed = 10;
    public bool cameraFlag = true;

    // Use this for initialization
	void Start () {
	    Rigidbody rigidbody = GetComponent<Rigidbody>();
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void FixedUpdate()
	{
		float z =  Input.GetAxis("Horizontal");
		float x = Input.GetAxis("Vertical");


		// rigidbodyのx軸（横）とz軸（奥）に力を加える
		rigidbody.AddForce(x * speed, 0, -z * speed);
	}

    void OnCollisionEnter(Collision c)
    {
        if (c.gameObject.tag == "Pin")
        {
            Debug.Log("HIT");
            cameraFlag = false;
        }
    }

    void OnTriggerEnter(Collider c)
    {
        if (c.gameObject.tag == "Item")
        {
            Debug.Log("HIT!");
            rigidbody.AddForce(transform.forward * 10000);
            Destroy(c.gameObject);

        }
    }
}
