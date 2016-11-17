using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEditor;
using UnityEngine.UI;

public class ballScript : MonoBehaviour
{
	public GameObject ballPrefab;
	public Sprite[] ballSprites;
	public LimitTimeScript LimitTimeScript;
	public List<GameObject> balls;
	public GameObject scoreGUI;
	private int score = 0;

	// Use this for initialization
	void Start ()
	{
		StartCoroutine(DropBall(70));
	}
	
	// Update is called once per frame
	void Update () {
		if ((int) LimitTimeScript.limitTime != 0)
		{
			if (Input.GetMouseButtonDown(0) && balls.Count == 0)
			{
				DragStart();
			}
			else if (Input.GetMouseButton(0) && balls.Count != 0)
			{
				Draging();
			}
			else if (Input.GetMouseButtonUp(0))
			{
				DragFinish();
			}
		}
	}

	IEnumerator DropBall(int num)
	{
		for (int i = 0; i < num; i++)
		{
			Vector2 pos = new Vector2(Random.Range(-2.0f, 2.0f), 4f);
			GameObject ball = Instantiate(ballPrefab, pos, Quaternion.AngleAxis(Random.Range(-40, 40), Vector3.forward)) as GameObject;
			int spriteID = Random.Range(0, 5);
			ball.name = "Piyo" + spriteID;
			SpriteRenderer spriteObj = ball.GetComponent<SpriteRenderer>();
			spriteObj.sprite = ballSprites[spriteID];
			yield return new WaitForSeconds(0.05f);
		}
	}

	void DragStart()
	{
		RaycastHit2D hit = Physics2D.Raycast(Camera.main.ScreenToWorldPoint(Input.mousePosition), Vector2.zero);
		if (hit)
		{
			GameObject hitObj = hit.collider.gameObject;
			Debug.Log(hitObj.name);
			if (hitObj.name.StartsWith("Piyo"))
			{
				balls.Add(hitObj);
				changeColor(hitObj);
			}
		}
	}

	void Draging()
	{
			RaycastHit2D hit = Physics2D.Raycast(Camera.main.ScreenToWorldPoint(Input.mousePosition), Vector2.zero);
		if (hit.collider != null)
		{
			if (hit.collider.gameObject != balls.Last() && hit.collider.gameObject.name == balls.Last().name && Vector2.Distance (hit.collider.gameObject.transform.position, balls.Last().transform.position) < 1.0f)
			{
				balls.Add(hit.collider.gameObject);
				changeColor(hit.collider.gameObject);
			}
		}
	}

	void DragFinish()
	{
		if (balls.Count > 2)
		{
			for (int i = 0; i < balls.Count; i++)
			{
				Destroy(balls[i]);
			}
			score += 100 * balls.Count;
			scoreGUI.GetComponent<Text>().text = "SCORE:" + score;
			StartCoroutine(DropBall(balls.Count));
		}
		else
		{
			rechangeColor(balls);
		}
		balls.Clear();
	}

	void changeColor(GameObject ball)
	{
		ball.GetComponent<SpriteRenderer>().color = new Color(ball.GetComponent<SpriteRenderer>().color.r, ball.GetComponent<SpriteRenderer>().color.g, ball.GetComponent<SpriteRenderer>().color.b, 0.5f);
	}

	void rechangeColor(List<GameObject> balls)
	{
		for (int i = 0; i < balls.Count; i++)
		{
			balls[i].GetComponent<SpriteRenderer>().color = new Color(balls[i].GetComponent<SpriteRenderer>().color.r, balls[i].GetComponent<SpriteRenderer>().color.g, balls[i].GetComponent<SpriteRenderer>().color.b, 1.0f);
		}
	}
}
