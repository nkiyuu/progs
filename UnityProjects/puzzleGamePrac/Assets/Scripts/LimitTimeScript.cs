using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class LimitTimeScript : MonoBehaviour
{

	public float limitTime;
	public GameObject GameOverPanel;
	// Use this for initialization
	void Start ()
	{
		GetComponent<Text>().text = ((int)limitTime).ToString();
		GameOverPanel.SetActive(false);
	}
	
	// Update is called once per frame
	void Update ()
	{
		if (limitTime >= 0)
		{
			limitTime -= Time.deltaTime;
			GetComponent<Text>().text = ((int) limitTime).ToString();
		}
		else
		{
				GameOver();
		}

	}

	void GameOver()
	{

		GameOverPanel.SetActive(true);
		if (Input.GetMouseButtonDown(0))
		{
			Application.LoadLevel("title");
		}
	}
}
