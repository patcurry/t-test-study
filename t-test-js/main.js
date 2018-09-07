const fs = require('fs');
const fcsv = require('fast-csv');

// before getting the file and dealing with it
// define all the math functions
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

// test the t-test
// the answer should be {'T Score': 2.514866859365871, 'dof': 8}

// array1 = [1, 2, 3, 4, 5];
// array2 = [3, 4, 5, 6, 7];

// console.log(twoSampleTTest(array1, array2));

// now get the file data, stream it, parse it, then run the functions on it
const inputFile = './height-data.csv';
const stream = fs.createReadStream(inputFile);

// I don't really like this method. Promises seriously confuse me.
const dataPromise = new Promise( resolve => {
    const heightData = [];
    fcsv.fromStream(stream, {headers:true})
    .on('data', data => {
        heightData.push(data)
        return heightData;
    })
    .on('end', () => {
        const maleHeights = heightData.map(x => parseInt(x.male));
        const femaleHeights = heightData.map(x => parseInt(x.female));
        const result = twoSampleTTest(maleHeights, femaleHeights)
        console.log(result);
    })
});

/*
const expected = [{ male: '188', female: '157' },
{ male: '172', female: '175' },
{ male: '177', female: '167' },
{ male: '183', female: '167' },
{ male: '180', female: '164' },
{ male: '183', female: '170' },
{ male: '175', female: '165' },
{ male: '183', female: '160' },
{ male: '190', female: '167' },
{ male: '178', female: '172' }];

const maleHeights = expected.map(x => parseInt(x.male));
const femaleHeights = expected.map(x => parseInt(x.female));
console.log(twoSampleTTest(maleHeights, femaleHeights));
*/