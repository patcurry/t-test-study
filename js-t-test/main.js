const fs = require('fs');
const fcsv = require('fast-csv');

const mean = arr => arr.reduce((acc, curr) => acc + curr) / arr.length;

const sampleStdDevDenom = arr => arr.reduce(
    (acc, curr) => acc + curr) / (arr.length - 1);

const squareDiffs = arr => arr.map(
    val => (val - mean(arr)) * (val - mean(arr))
);

const stdDev = arr => Math.sqrt(sampleStdDevDenom(squareDiffs(arr)));

const twoSampleTTest = (arr1, arr2) => {
    const numerator = Math.abs(mean(arr1) - mean(arr2));
    const arr1_denom = stdDev(arr1) / arr1.length;
    const arr2_denom = stdDev(arr2) / arr2.length;
    const denominator = Math.sqrt(arr1_denom + arr2_denom);
    const dof = arr1.length + arr2.length - 2;
    const tScore = numerator / denominator;
    return { 'T Score': tScore, 'dof': dof };
}

// now get the file data, stream it, parse it, then run the functions on it
const inputFile = './height-data.csv';
const stream = fs.createReadStream(inputFile);

const heightData = [];
fcsv.fromStream(stream, { headers: true })
    .on('data', data => {
        heightData.push(data)
        return heightData;
    })
    .on('end', () => {
        const maleHeights = heightData.map(x => parseInt(x.male));
        const femaleHeights = heightData.map(x => parseInt(x.female));
        const result = twoSampleTTest(maleHeights, femaleHeights)
        console.log(result);
    });

// test the t-test
// the answer should be {'T Score': 2.514866859365871, 'dof': 8}

// array1 = [1, 2, 3, 4, 5];
// array2 = [3, 4, 5, 6, 7];

// console.log(twoSampleTTest(array1, array2));
