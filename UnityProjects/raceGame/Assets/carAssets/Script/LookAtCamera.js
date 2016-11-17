private var select : GameObject;

function Update(){
transform.rotation = Quaternion.LookRotation(-Camera.main.transform.forward);
// gameObject.SetActive (false);  // Unite 2015
}