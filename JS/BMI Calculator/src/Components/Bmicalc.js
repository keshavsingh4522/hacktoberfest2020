import React, { useState } from 'react';

const Bmicalc = () => {
  
  const [weightInput, setWeightInput] = useState();
  const [heightInput, setHeightInput] = useState();
  const [bmi, setBmi] = useState(0);
  const [status, setStatus] = useState();

  const weightChangeHandler = (e) => {
    setWeightInput(e.target.value);
  };

  const heightChangeHandler = (e) => {
    setHeightInput(e.target.value);
  };

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
        setStatus('Under Weight');
      } else if (bmi >= 18.5 && bmi < 24.9) {
        setStatus('Normal' || 'Healthy Weight');
      } else if (bmi >= 24.9 && bmi < 29.9) {
        setStatus('Overweight');
      } else {
        setStatus('Obese');
      }
    } else {
      setStatus('NaN');
      setBmi('NaN');
    }
  };

  return (
    <>
      <form onSubmit={calculate}>
        <p className='my-4'>Weight</p>
        <input
          type='number'
          placeholder='Enter weight'
          value={weightInput}
          onChange={weightChangeHandler}
          className='border-2 rounded p-2'
        />
        <p className='my-4'>Height</p>
        <input
          type='number'
          placeholder='Enter height'
          value={heightInput}
          onChange={heightChangeHandler}
          className='border-2 rounded p-2 mb-5'
        />
        <button
          className='flex justify-center items-center text-center py-2 px-3 bg-blue-800 hover:bg-blue-600 focus:outline-none text-white rounded-lg'
          type='submit'
        >
          Submit
        </button>
      </form>
      <div>
        <p >Your BMI is {bmi}</p>
        <p >This is considered {status}</p>
      </div>
    </>
  );
};

export default Bmicalc;
