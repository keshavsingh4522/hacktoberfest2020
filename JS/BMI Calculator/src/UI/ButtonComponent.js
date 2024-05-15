const ButtonComponent = (props) => {
  const { label, type = "button" } = props;
  return (
    <button
      className="flex justify-center items-center text-center py-2 px-3 bg-blue-800 hover:bg-blue-600 focus:outline-none text-white rounded-lg"
      type={type}
    >
      {label}
    </button>
  );
};

export default ButtonComponent;
