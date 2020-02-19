function generate() {
    var allButtons = document.createElement("div");
    allButtons.className = "buttonDiv";
    var buttons = [];
    var buttonIDS = ["log", "warn", "error", "aqua"];

    for(var i = 0; i < buttonIDS.length; i++) {
        var tempButton = document.createElement("button");
        tempButton.id = buttonIDS[i];
        tempButton.innerHTML = buttonIDS[i];
        tempButton.onclick = function() {
            var elementsOfClass = document.getElementsByClassName(this.id);
            var hide = true;
            if(elementsOfClass[0].style.display == "none") hide = false;
            for(var i = 0; i < elementsOfClass.length; i++) {
                if(hide) {
                    elementsOfClass[i].style.display = "none";
                } else {
                    elementsOfClass[i].style.display = "block";
                }
            }
        }
        allButtons.appendChild(tempButton);
    }
    document.body.appendChild(allButtons);
}