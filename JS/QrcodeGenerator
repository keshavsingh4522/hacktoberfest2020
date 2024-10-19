$(document).ready(function() {
    $('#generateButton').click(function() {
        const privateKey = $('#privateKey').val();
        if (privateKey) {
            $('#qrcode').empty(); // Clear previous QR code
            $('#downloadContainer').addClass('hidden'); // Hide download link
            $('#qrcode').hide(); // Hide the QR code container initially

            // Generate QR code
            const qr = qrcode(0, 'L'); // Error correction level L
            qr.addData(privateKey);
            qr.make();

            // Create an image element to hold the QR code with larger size
            const imgTag = qr.createImgTag(6); // Increased size for larger QR code
            $('#qrcode').append(imgTag); // Append the image to the #qrcode div

            // Create a downloadable QR code image
            const qrImgUrl = qr.createDataURL(6); // Get the image URL
            $('#downloadLink').attr('href', qrImgUrl); // Set the href attribute to the image URL
            $('#downloadLink').attr('download', 'qr-code.png'); // Set the download attribute to specify the filename
            $('#downloadContainer').removeClass('hidden'); // Show download link
            
            // Show notification
            showNotification('QR Code generated successfully!');

            // Slide down the QR code container
            $('#qrcode').slideDown(500); // Slide down animation
        } else {
            alert('Please enter a valid private key.');
        }
    });
});

function showNotification(message) {
    const notification = $('#notification');
    notification.text(message).fadeIn(300).delay(2000).fadeOut(300); // Show notification, keep for 2 seconds, then hide
}
