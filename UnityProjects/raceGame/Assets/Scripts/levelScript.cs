using UnityEngine;
using System.Collections;
using System.Net.Mime;
using UnityEditor;
using UnityEngine.UI;

public class levelScript : MonoBehaviour
{
    public float level = 1;
    private float initValue = 1000;
    private int levelUpDist = 5;
    public Text LevelGUI;

	// Use this for initialization
	void Start ()
	{
	    //initValue = transform.position.z;
	    LevelGUI.text = "Level:" + level.ToString();
	}
	
	// Update is called once per frame
	void Update () {
	    if (transform.position.z >= initValue + levelUpDist)
	    {
	        Debug.Log("test");
	        level++;
	        levelUpDist += 5;
	        LevelGUI.text = "Level:" + level.ToString();
	    }
	}
}
