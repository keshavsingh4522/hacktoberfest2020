const rgbToHex = (red, green, blue) => {
	if (typeof red !== 'number' || typeof green !== 'number' || typeof blue !== 'number') {
		throw new TypeError('argument is not a Number');
	}

	const toHex = n => (n || '0').toString(16).padStart(2, '0');

	return `#${toHex(red)}${toHex(green)}${toHex(blue)}`;
};

console.log(rgbToHex(255, 255, 255) === '#ffffff');
