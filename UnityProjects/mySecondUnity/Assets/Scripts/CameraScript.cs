using UnityEngine;
using System.Collections;

public class CameraScript : MonoBehaviour
{
    public Transform target;
    private Vector3 offset;
    // Use this for initialization
	void Start ()
	{
	    offset = GetComponent<Transform>().position - target.position;
	}
	
	// Update is called once per frame
	void Update ()
	{
	  GetComponent<Transform>().position = target.position + offset;
	}
}
