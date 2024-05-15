import { Fragment } from "react";

const InputComponent = (props) => {
  const { label, placeHolder, value, setValue, type = "text" } = props;
  return (
    <Fragment>
      <p className="my-4">{label}</p>
      <input
        type={type}
        placeholder={placeHolder}
        value={value}
        onChange={(e) => setValue(e.target.value)}
        className="border-2 rounded p-2 mb-5"
      />
    </Fragment>
  );
};

export default InputComponent;
