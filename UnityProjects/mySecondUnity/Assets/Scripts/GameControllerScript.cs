using UnityEngine;
using System.Collections;

public class GameControllerScript : MonoBehaviour
{
    public UnityEngine.UI.Text scoreLabel;
    public int countSt;

    // Use this for initialization
    void Start () {
      countSt = GameObject.FindGameObjectsWithTag("Item").Length;
    }

    // Update is called once per frame
    void Update ()
    {
      int count = GameObject.FindGameObjectsWithTag("Item").Length;
      scoreLabel.text = "score:" + count.ToString() + "/" + countSt.ToString();
    }
}
