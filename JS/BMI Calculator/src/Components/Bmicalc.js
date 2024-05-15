import React, { useState } from "react";
import ButtonComponent from "../UI/ButtonComponent";
import InputComponent from "../UI/InputComponent";

const Bmicalc = () => {
  const [weightInput, setWeightInput] = useState();
  const [heightInput, setHeightInput] = useState();
  const [bmi, setBmi] = useState(0);
  const [status, setStatus] = useState();

  const calculate = (e) => {
    e.preventDefault();
    const isValid =
      +heightInput > 0 &&
      +weightInput > 0 &&
      +heightInput < 500 &&
      +weightInput < 250;

    if (isValid) {
      let heightInMeter = +heightInput / 100;
      const bmi = +weightInput / (+heightInMeter) ** 2;
      setBmi(bmi.toFixed(2));
      if (bmi > 0 && bmi < 18.5) {
        setStatus("Under Weight");
      } else if (bmi >= 18.5 && bmi < 24.9) {
        setStatus("Normal" || "Healthy Weight");
      } else if (bmi >= 24.9 && bmi < 29.9) {
        setStatus("Overweight");
      } else {
        setStatus("Obese");
      }
    } else {
      setStatus("NaN");
      setBmi("NaN");
    }
  };

  return (
    <>
      <form onSubmit={calculate}>
        <InputComponent
          label="Weight"
          type="number"
          placeHolder="Enter weight"
          value={weightInput}
          setValue={setWeightInput}
        />

        <InputComponent
          label="Height"
          type="number"
          placeHolder="Enter hheight"
          value={heightInput}
          setValue={setHeightInput}
        />

        <ButtonComponent type="submit" label="Submit" />
      </form>
      <div>
        <p className="">Your BMI is {bmi}</p>
        <p className="">This is considered {status}</p>
      </div>
    </>
  );
};

export default Bmicalc;
