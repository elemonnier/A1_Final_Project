function printResultSearchError() {
    let newImage = document.createElement("img");
    newImage.setAttribute("src", "SP.jpg");
    document.getElementById("tmp1").appendChild(newImage);

    let newText = document.createElement("h1");
    newText.innerText = "Cet élément n'existe pas";
    document.getElementById("tmp2").appendChild(newText);
}

function main() {
    printResultSearchError();
}

main();