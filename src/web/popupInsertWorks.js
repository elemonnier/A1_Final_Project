function printResultInsertWorks() {
    let newImage = document.createElement("img");
    newImage.setAttribute("src", "SC.jpg");
    document.getElementById("tmp1").appendChild(newImage);

    let newText = document.createElement("h1");
    newText.innerText = "Ajout réussi !"; //TODO AJOUTER TITRE ETC
    document.getElementById("tmp2").appendChild(newText);
}

function main() {
    printResultInsertWorks();
}

main();