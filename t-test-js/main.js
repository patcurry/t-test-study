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

// I am getting a different value here
// this is where the problem is
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
    const res = Math.sqrt(numerator / (d.length - 1));

    return res;
}

const twoSampleTTest = (a, b) => {
    const count_a = a.length;
    const count_b = b.length;
    const numerator = Math.abs(mean(a) - mean(b));
    const a_denom = stdDev(a) / count_a;
    const b_denom = stdDev(b) / count_b;
    const denominator = Math.sqrt(a_denom + b_denom);
    const dof = count_a + count_b - 2;
    const tScore = numerator / denominator;

    // getting a different answer than one written in python
    // why?
    return { 'T Score': tScore, 'dof': dof };
}


array1 = [1, 2, 3, 4, 5];
array2 = [3, 4, 5, 6, 7];

//console.log(twoSampleTTest(array1, array2));
console.log(stdDev(array1))