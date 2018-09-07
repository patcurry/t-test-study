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

// The math is here. I just need to apply it to the data now.
const mean = d => d.reduce((acc, curr) => acc + curr) / d.length;

const sampleStdDevDenom = d => d.reduce((acc, curr) => acc + curr) / (d.length - 1);

const squareDiffs = d => {
    // get mean
    // use map to subtract values and mean
    // then square the result
    // then return the results as a list 
    const avg = mean(d);
    return d.map(val => {
        const diff = val - avg;
        return diff * diff;
    });
}

const stdDev = d => {
    /*
    const sd = squareDiffs(d);
    const MSD = sampleStdDevDenom(sd);
    const res = Math.sqrt(MSD);
    return res;
    */
    // oneline
    return Math.sqrt(sampleStdDevDenom(squareDiffs(d)));
}

const twoSampleTTest = (a, b) => {
    const numerator = Math.abs(mean(a) - mean(b));
    const a_denom = stdDev(a) / a.length;
    const b_denom = stdDev(b) / b.length;
    const denominator = Math.sqrt(a_denom + b_denom);
    const dof = a.length + b.length - 2;
    const tScore = numerator / denominator;
    return { 'T Score': tScore, 'dof': dof };
}

array1 = [1, 2, 3, 4, 5];
array2 = [3, 4, 5, 6, 7];

console.log(twoSampleTTest(array1, array2));
console.log(stdDev(array1))