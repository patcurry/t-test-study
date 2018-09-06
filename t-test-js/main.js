const fs = require('fs');
const fcsv = require('fast-csv');

// get file data and stream it
const inputFile = './height-data.csv';
const stream = fs.createReadStream(inputFile);

// make empty object to hold the data
const heightData = [];

// add height data to heightData object
// this is asynchronous and therefore obnoxious
fcsv.fromStream(stream, { headers: true })
    .on('data', data => heightData.push(data))
    .on('end', () => heightData);

// now this whole thing has to work on sort of a promises or async-await
// type framework

const mean = d => d.reduce((acc, curr) => acc + curr) / d.length;

const stdDev = d => {
    // get mean
    const mean_d = mean(d);

    // acc is accumulator and curr is current
    // subtract the mean from the current value, square it
    // and add it to the accumulator
    const numerator = d.reduce(
        (acc, curr) => acc + Math.pow(curr - mean_d, 2)
    );

    // divide numerator by the length of the array - 1 
    const res = Math.sqrt(numerator/(d.length-1));

    return res;
}

array1 = [1,2,3,4,5]
console.log(stdDev(array1));

//console.log(array1.reduce((acc, curr) => acc + curr))
/*
console.log(array1.reduce((acc, curr) => acc + curr));
console.log(mean(array1));
*/

