public var startRange : float = 10; //your chosen start value
public var endRange : float = 50; //your chose end value
public var speed = 20;
public var startFirst = true;


function  Update () { 

var oscilationRange = (endRange - startRange)/2;
var oscilationOffset = oscilationRange + startRange;

if (startFirst == true ){
//gameObject.GetComponent(LensFlare).brightness = Mathf.Sin(Time.time * speed) * value;
gameObject.GetComponent(LensFlare).brightness = oscilationOffset + Mathf.Sin(Time.time * speed) * oscilationRange;
}
else if (startFirst == false ){
//gameObject.GetComponent(LensFlare).brightness = Mathf.Sin(Time.time * speed) * -value;
gameObject.GetComponent(LensFlare).brightness = oscilationOffset + Mathf.Sin(Time.time * speed) * -oscilationRange;
}

} 

