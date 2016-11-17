using UnityEngine;
using System.Collections;

public class CameraScripts : MonoBehaviour {

    public Transform target;
    public GameObject bowl;
    private Vector3 offset;
    private bool flag = true;
	// Use this for initialization
	void Start () {
	    offset = GetComponent<Transform>().position - target.position;
	}
	
	// Update is called once per frame
    void Update()
    {
        if (bowl.GetComponent<BowlScript>().cameraFlag)
        {
            GetComponent<Transform>().position = target.position + offset;
        }
    }

//    void OnCollisionEnter(Collision c)
//    {
//        Debug.Log("HIT");
//        flag = false;
//    }
}
