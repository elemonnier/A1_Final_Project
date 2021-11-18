function printResultSearchWorks() {
    let newImage = document.createElement("img");
    newImage.setAttribute("src", "SC.jpg");
    document.getElementById("tmp1").appendChild(newImage);

    let newText = document.createElement("h1");
    newText.innerText = "Trouvé !";
    document.getElementById("tmp2").appendChild(newText);
}

function readFileByName(fileName) {

    let xhr = new XMLHttpRequest();
    do {
        xhr.open("GET", fileName, false);
        xhr.send(null);

    } while(xhr.status === 404);

    // assumes status 200
    return xhr.responseText;
}

function readFile() {
    readFileByName("ready.txt");
    return readFileByName("results.txt");
}

function replaceLineBreaksBySemicolons(string) {
    let tmp = "";
    for (let counter = 0; counter < string.length; counter++){
        if (string[counter] === '\n'){
            tmp += ';';
        }
        else {
            tmp += string[counter];
        }
    }
    return tmp;
}

function numberRowsByLineBreaks(string) {
    let number = 0;
    for (let counter = 0; counter < string.length; counter++){
        if (string[counter] === '\n'){
            number++;
        }
    }
    return number + 1;
}

function completeColumn(counter, counter2, s) {
    let columnValue = document.createElement("td");
    columnValue.innerText = s[counter];
    document.getElementById("tr-" + counter2 / 4).appendChild(columnValue);
}

function printBooks(s) {

    let n = numberRowsByLineBreaks(s);
    s = replaceLineBreaksBySemicolons(s);
    s = s.split(';');

    for (let counter = 0; counter < n; counter++) {
        let newTr = document.createElement("tr");
        newTr.id = "tr-" + counter;
        if (counter%2 === 0) {
            newTr.setAttribute("class", "evenRow");
        }
        else {
            newTr.setAttribute("class", "oddRow");
        }
        document.getElementById("tbody").appendChild(newTr);
    }

    for (let counter = 0; counter < s.length; counter+=4) {
        completeColumn(counter, counter, s);
        completeColumn(counter+1, counter, s);
        completeColumn(counter+2, counter, s);
        completeColumn(counter+3, counter, s);
    }
}

function printTime(time) {
    let s = readFile();
    let n = numberRowsByLineBreaks(s);
    let newText = document.createElement("h2");
    if (n >= 2) {
        newText.innerText = n + " résultats trouvés en " + time + "ms";
    }
    else {
        newText.innerText = n + " résultat trouvé en " + time + "ms";
    }
    document.body.insertBefore(newText, document.getElementById("table"));
}

function main() {
    let startTime = new Date().getTime();
    let elapsedTime;
    let s = readFile();
    printResultSearchWorks();
    printBooks(s);
    elapsedTime = new Date().getTime() - startTime;
    printTime(elapsedTime);
}

main();