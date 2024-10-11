const apiKey = 'YOUR_API_KEY'; // Replace with your API key from api-ninjas

// Fetch a random quote from the Ninja API based on the selected category
async function getRandomQuote(category) {
    const apiKey = 'LiBjVnD6uNfUF7snLSRYHA==TMcG60tXyAxBVbH7';  // Replace with your actual API key
    const url = `https://api.api-ninjas.com/v1/quotes?category=${category}`;
    try {
        const response = await fetch(url, {
            method: 'GET',
            headers: {
                'X-Api-Key': apiKey
            }
        });

        if (!response.ok) {
            throw new Error('Failed to fetch quote');
        }

        const data = await response.json();
        
        // Return the fetched quote object (first quote)
        return {
            quote: data[0].quote,
            source: data[0].author
        };
    } catch (error) {
        console.error('Error fetching quote:', error);
        return {
            quote: 'Sorry, no quote found for this category.',
            source: ''
        };
    }
}

// Function to display the quote
async function printQuote() {
    const category = document.getElementById("category").value; // Get selected category
    const quotes = await getRandomQuote(category);  // Fetch the random quote
    const quoteContainer = document.getElementById("quote-box");

    // Construct the HTML to display the quote and source
    let quoteString = `<p class="quote">"${quotes.quote}"</p><p class="source">${quotes.source}</p>`;
    
    quoteContainer.innerHTML = quoteString;

    // Assign a random color to the document background
    document.body.style.backgroundColor = getRandomColor();
}

// Function to select random RGB color value
function getRandomColor() {
    var red = Math.floor(Math.random() * 256);
    var green = Math.floor(Math.random() * 256);
    var blue = Math.floor(Math.random() * 256);
    var randomColor = 'rgb(' + red + ',' + green + ',' + blue + ')';
    return randomColor;
}

// Event listener on the LoadQuote button to generate a new quote
document.getElementById("loadQuote").addEventListener("click", printQuote);
