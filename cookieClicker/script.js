var clicks = 0;
var moon = document.getElementById("moon");
var counter = document.getElementById("counter");

moon.onclick = function(){
  clicks++;
  counter.innerHTML = clicks;
  if(moon.className == "shrinked"){
      moon.className == ""
  } else{
        moon.className = "shrinked"
  }
}