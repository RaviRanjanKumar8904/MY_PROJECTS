// get all the html stuff
var dateInput = document.getElementById('date');
var monthInput = document.getElementById('month');
var yearInput = document.getElementById('year');
var findDayButton = document.getElementById('findDayButton');
var errorMessage = document.getElementById('errorMessage');
var resultMessage = document.getElementById('resultMessage');

// when button is clicked
findDayButton.addEventListener('click', function() {
    
    // clear old results
    errorMessage.textContent = '';
    resultMessage.textContent = '';

    // get the numbers from the boxes
    var d = parseInt(dateInput.value);
    var m = parseInt(monthInput.value); // Month is 1-12 from user
    var y = parseInt(yearInput.value);

    // check if inputs are valid (like in my C code)
    if (isNaN(d) || isNaN(m) || isNaN(y)) {
        errorMessage.textContent = 'Please fill in all fields.';
        return; // stop
    }

    if (m <= 0 || m >= 13) {
        // Use \n for new line, just like in C
        errorMessage.textContent = 'Invalid Entry!!\n Month must be between 1 - 12';
        return;
    }

    if (d <= 0 || d >= 32) {
        errorMessage.textContent = 'Invalid Entry!!\n Date must be between 1 - 31';
        return;
    }

    if (y <= 0) {
        errorMessage.textContent = 'Invalid Entry!!\n Year must be a positive number.';
        return;
    }

    // --- Start calculation ---
    
    // 1. Year Code
    var yc; // yearCode
    var century = Math.floor(y / 100);
    if (century % 4 === 0) {
        yc = 6;
    } else if (century % 4 === 1) {
        yc = 4;
    } else if (century % 4 === 2) {
        yc = 2;
    } else if (century % 4 === 3) {
        yc = 0;
    }

    // 2. Last two digits
    var lastTwo = y % 100;

    // 3. Month Code
    var mc; // monthCode
    switch (m) {
        case 1: mc = 0; break; // Jan
        case 2: mc = 3; break; // Feb
        case 3: mc = 3; break; // Mar
        case 4: mc = 6; break; // Apr
        case 5: mc = 1; break; // May
        case 6: mc = 4; break; // Jun
        case 7: mc = 6; break; // Jul
        case 8: mc = 2; break; // Aug
        case 9: mc = 5; break; // Sep
        case 10: mc = 0; break; // Oct
        case 11: mc = 3; break; // Nov
        case 12: mc = 5; break; // Dec
    }

    // 4. Final formula from C code
    // day = LastTWoDigitOfYear + (LastTWoDigitOfYear / 4) + d + yearCode + monthCode
    var dayIndex = (lastTwo + Math.floor(lastTwo / 4) + d + yc + mc) % 7;

    // 5. Get Day Name
    var dayName;
    if (dayIndex === 0) {
        dayName = "Sunday";
    } else if (dayIndex === 1) {
        dayName = "Monday";
    } else if (dayIndex === 2) {
        dayName = "Tuesday";
    } else if (dayIndex === 3) {
        dayName = "Wednesday";
    } else if (dayIndex === 4) {
        dayName = "Thrusday"; // Keep the typo from the C code
    } else if (dayIndex === 5) {
        dayName = "Friday";
    } else if (dayIndex === 6) {
        dayName = "Saturday";
    }
    
    // Show the answer
    resultMessage.textContent = 'The day is ' + dayName + '.';
});
// thankyou