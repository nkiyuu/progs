using UnityEngine;
using System.Collections;
using ADInterstitialAd = UnityEngine.iOS.ADInterstitialAd;

public class AddBarScript : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {

	}

    void OnCollisionEnter(Collision co)
    {
        if (co.gameObject.tag == "Ball")
        {
            Debug.Log("hit!!");
            Rigidbody BallRd = co.gameObject.GetComponent<Rigidbody>();
            BallRd.AddForce(0, 0, -200f);
        }
    }
}
