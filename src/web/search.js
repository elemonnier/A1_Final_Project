function readFileByName(fileName) {

    let xhr = new XMLHttpRequest();
    do {
        xhr.open("GET", fileName, false);
        xhr.send(null);

    }while(xhr.status === 404);

    // assumes status 200
    return xhr.responseText;
}

function readFile() {
    readFileByName("ready.txt");
    return readFileByName("results.txt");
}

function writeFile(id_form,func) {

    var element = document.createElement('a');

    let text1 = document.getElementById(id_form);
    let count = text1.elements.length+1;
    let textToSave = func;
    for(let i = 0;i<count-1;i++){
        textToSave += ";" + text1[i].value;
    }

    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(textToSave));
    element.setAttribute('download', 'request.txt');

    element.style.display = 'none';
    document.body.appendChild(element);
    element.click();
    document.body.removeChild(element);

    text1.submit();
}

function printRequest(event) {
    event.preventDefault();
    writeFile("form", "searchBy");
}

function main() {
    let button = document.getElementById("button");
    button.addEventListener("click", printRequest);

    // TODO TRAITEMENT REQUETE / REPONSE + NOUVELLE PAGE

    // let s = 1;
    // if (s === 0){ // if DOESN'T EXIST
    //     document.getElementById("form").setAttribute("action", "popupSearchError.html");
    // }
    // else {
        document.getElementById("form").setAttribute("action", "popupSearchWorks.html");
    // }
}

main();