

const gmInput = document.getElementById("gramInput");
const poundInput = document.getElementById("poundInput");
const ounceInput = document.getElementById("ounceInput");
const kgInput = document.getElementById("kgInput");

const input = document.getElementById("input");

const poundSelect = document.getElementById("poundSelect");
const kgSelect = document.getElementById("kgSelect");
const gmSelect = document.getElementById("gramSelect");
const ounceSelect = document.getElementById("ounceSelect");

select = document.getElementById("select");
// inputs = document.querySelectorAll(".inputs");

//Events

input.addEventListener("input", myResult);
select.addEventListener("change", myResult);

//For Pound
card = document.getElementById("card");
card.style.visibility = "hidden";

input.addEventListener("keyup", () => {
  card.style.visibility = "visible";
});

function myResult() {
  if (select.value === "pound") {
    poundSelect.style.display = "none";
    kgSelect.style.display = "block";
    gmSelect.style.display = "block";
    ounceSelect.style.display = "block";
    if (input.value === "") {
      inputsFunction();
    } else {
      forPounds();
    }
  } else if (select.value === "kg") {
    input.placeholder = "Enter The Number in Kg";
    kgSelect.style.display = "none";
    gmSelect.style.display = "block";
    poundSelect.style.display = "block";
    ounceSelect.style.display = "block";
    if (input.value === "") {
      inputsFunction();
    } else {
      poundInput.textContent = `${input.value}kg is ${input.value * 2.20462}pounds`;
      ounceInput.textContent = `${input.value}kg is ${
        input.value * 35.2739619
      } ounce`;
      gmInput.textContent = `${input.value}kg is ${input.value * 1000}gm`;
    }
  } else if (select.value === "gram") {
    input.placeholder = "Enter The Number in gram";
    gmSelect.style.display = "none";
    kgSelect.style.display = "block";
    poundSelect.style.display = "block";
    ounceSelect.style.display = "block";
    if (input.value === "") {
      inputsFunction();
    } else {
      poundInput.textContent = `${input.value}gm is ${
        input.value * 0.0022046226
      }pounds`;
      ounceInput.textContent = `${input.value}gm is ${
        input.value * 0.0352739619
      }ounces`;
      kgInput.textContent = `${input.value}gm is ${input.value * 1000}kg`;
    }
  } else {
    input.placeholder = "Enter The Number in Ounce";
    ounceSelect.style.display = "none";
    gmSelect.style.display = "block";
    poundSelect.style.display = "block";
    kgSelect.style.display = "block";
    if (input.value === "") {
      inputsFunction();
    } else {
      poundInput.textContent = `${input.value}ounce is ${
        input.value * 0.0625
      }pounds`;
      kgInput.textContent = `${input.value}ounce is ${
        input.value * 0.0283495231
      }kg`;
      gmInput.textContent = `${input.value}ounce is ${
        input.value / 28.3495321
      }gm`;
    }
  }
}

function inputsFunction() {
  inputs.forEach((input) => {
    input.textContent = "";
  });
}

function forPounds() {
  kgInput.textContent = `${input.value} pounds is ${
    input.value * 0.45359237
  }kg`;
  ounceInput.textContent = `${input.value} pounds is ${input.value * 16}ounces`;
  gmInput.textContent = `${input.value} pounds is ${input.value * 453.59237}gm`;
}
