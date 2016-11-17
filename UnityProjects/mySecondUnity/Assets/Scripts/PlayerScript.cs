using System;
using UnityEngine;
using System.Collections;

public class PlayerScript : MonoBehaviour {

    // Use this for initialization
    void Start () {

    }

    // Update is called once per frame
    void Update ()
    {

    }

    public float speed = 100;

    //物理演算でキャラクターが動くたびに呼ばれる
    void FixedUpdate()
    {
    	float x = Input.GetAxis("Horizontal");
    	float z = Input.GetAxis("Vertical");

    	Rigidbody rigidbody = GetComponent<Rigidbody>();
	    rigidbody.AddForce(x * speed, 0, z * speed);
    }
}
