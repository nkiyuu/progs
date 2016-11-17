using UnityEngine;
using System.Collections;

public class moveScripts : MonoBehaviour
{
    public float speed = 3;
	public float movePower = 0.0002f;
    private float LimitV = 5;
	public Rigidbody rd;
    public levelScript levelScript;

	// Use this for initialization
    void Start ()
    {
	    rd = GetComponent<Rigidbody>();
    }

	// Update is called once per frame
	void Update () {
	    speed = 2.5f + levelScript.level / 2;
	    Accel();
	}

	void FixedUpdate()
	{
	    //常に進む

		if (Input.GetKey("down"))
		{
			Brake();
		}
		if (Input.GetKey("right"))
		{
			Right();
		}
		if (Input.GetKey("left"))
		{
			Left();
		}
//		if (rd.velocity.z > 0)
//		{
//			rd.AddForce(new Vector3(0, 0, -speed * 0.01f));
//		}
//	    if (rd.velocity.z < 0)
//	    {
//	        rd.velocity = new Vector3(0, 0, 0);
//	    }
//	    if (rd.velocity.z > LimitV)
//	    {
//	        rd.velocity = new Vector3(0, 0, LimitV);
//	    }
	}

	void Accel()
	{
		rd.velocity = new Vector3(0, 0, speed);
	}

	void Brake()
	{
		rd.AddForce(new Vector3(0, 0, -speed * 0.5f));
	}

	void Right()
	{
		Vector3 temp = new Vector3(transform.position.x + movePower, transform.position.y, transform.position.z);
		rd.position = temp;
	}

	void Left()
	{
		Vector3 temp = new Vector3(transform.position.x - movePower, transform.position.y, transform.position.z);
		rd.position = temp;
	}

	void OnCollisionEnter(Collision col)
	{
		if (col.gameObject.tag == "Enemy")
		{
			rd.velocity = new Vector3(0, 0, 0);
		}
	}
}
