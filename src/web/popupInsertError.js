function printResultInsertError() {
    let newImage = document.createElement("img");
    newImage.setAttribute("src", "SP.jpg");
    document.getElementById("tmp1").appendChild(newImage);

    let newText = document.createElement("h1");
    newText.innerText = "Ce livre existe déjà";
    document.getElementById("tmp2").appendChild(newText);
}

function main() {
    printResultInsertError();
}

main();