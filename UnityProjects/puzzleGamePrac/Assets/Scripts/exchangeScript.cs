using UnityEngine;
using System.Collections;
using System.Net.Mime;

public class exchangeScript : MonoBehaviour
{
	public ballScript BallScript;

	public void Exchange()
	{
		GameObject[] piyos = GameObject.FindGameObjectsWithTag("Piyo");
		foreach (var piyo in piyos)
		{
			Destroy(piyo);
		}
		BallScript.SendMessage("DropBall", 70);
	}
}
