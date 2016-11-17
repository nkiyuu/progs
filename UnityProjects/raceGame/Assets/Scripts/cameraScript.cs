using UnityEngine;
using System.Collections;

public class cameraScript : MonoBehaviour
{
	//ランダムの敵
	public GameObject Enemy1;
	public GameObject Enemy2;
	public GameObject Enemy3;
	public GameObject Enemy4;

	private int EnemyBorder = 5;
    private float EnemyDist = 20;

	//無限マップ関連
	public GameObject Green1;
	public GameObject Green2;
	private int border = 1000;
	// Use this for initialization
	void Start () {

	}
	
	// Update is called once per frame
	void Update () {
		if (transform.position.z > border)
		{
			CreateMap();
		}
		if (transform.position.z > EnemyBorder)
		{
			CreateEnemy();
		}
	}

	void CreateMap()
	{
		if (Green1.transform.position.z < border)
		{
			border += 2000;
			Vector3 tmp = new Vector3(0, 0, border);
			Green1.transform.position = tmp;
		}
		else if (Green2.transform.position.z < border)
		{
			border += 2000;
			Vector3 tmp = new Vector3(0, 0, border);
			Green2.transform.position = tmp;
		}
	}

	void CreateEnemy()
	{
		if(Random.Range(0, 3) == 0)
		{
			Instantiate(Enemy1, new Vector3(-0.5f, 0.5f, EnemyBorder + EnemyDist), Enemy1.transform.rotation);
		}
		if(Random.Range(0, 3) == 0)
		{
			Instantiate(Enemy2, new Vector3(-0.25f, 0.5f, EnemyBorder + EnemyDist), Enemy2.transform.rotation);
		}
		if(Random.Range(0, 3) == 0)
		{
			Instantiate(Enemy3, new Vector3(0.5f, 0.5f, EnemyBorder + EnemyDist), Enemy3.transform.rotation);
		}
		if(Random.Range(0, 3) == 0)
		{
			Instantiate(Enemy4, new Vector3(0.25f, 0.5f, EnemyBorder + EnemyDist), Enemy4.transform.rotation);
		}
		EnemyBorder += 5;
	}
}
