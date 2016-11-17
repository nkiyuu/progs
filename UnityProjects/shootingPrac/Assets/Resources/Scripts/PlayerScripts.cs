using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using ADInterstitialAd = UnityEngine.iOS.ADInterstitialAd;

public class PlayerScripts : MonoBehaviour
{
    public float speed = 5f;
    private Rigidbody rb;
    public GameObject Bullet;
	public Text text;
	public int hp = 100;
	public GameObject Explosion;
	// Use this for initialization
	void Start ()
	{
	    rb = GetComponent<Rigidbody>();
		text.text = "HP:" + hp.ToString();
	}
	
	// Update is called once per frame
	private float intervalTime = 0.1f;
    void Update ()
    {
		//通常移動常に前に進む
        transform.position += new Vector3(0, 0, 0.1f);

        //-----------------キー操作-------------------------------------------------------
	    rb.velocity = new Vector3(0, 0, 0.1f);
	    if (Input.GetKey("up") && transform.position.y < 4.0f)
	    {
	        rb.velocity += new Vector3(0, speed, 0);
	    }
	    if(Input.GetKey("down") && transform.position.y > -1.4f)
	    {
	        rb.velocity += new Vector3(0, -speed, 0);
	    }
        if (Input.GetKey("right") && transform.position.x < 5.0f)
        {
            rb.velocity += new Vector3(speed, 0, 0);
        }
        if (Input.GetKey("left") && transform.position.x > -5.0f)
        {
            rb.velocity += new Vector3(-speed, 0, 0);
        }
	    intervalTime += Time.deltaTime;
	    if(Input.GetKeyDown("space") && intervalTime > 0.1f) Shoot();

        //---------------------------------------------------------------------------------
	}

    void Shoot()
    {
        intervalTime = 0.0f;
        Instantiate(Bullet, new Vector3(transform.position.x, transform.position.y, transform.position.z), Quaternion.identity);
    }

	void DecreaseHP()
	{
		hp -= 1;
		text.text = "HP:" + hp.ToString();
		if (hp == 0)
		{
			Instantiate(Explosion, transform.position, Quaternion.identity);
			Destroy(this.gameObject);
		}
	}

}
