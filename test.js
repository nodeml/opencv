const cv = require("./lib");

const testMat = cv.imread("./img.png");
console.log(
  "OH YEAH",
  testMat,
  testMat.shape,
  cv.resize(testMat, [testMat.shape[1] * 0.2, testMat.shape[2] * 0.2], cv.INTER_AREA)
    .shape
);

const grey = cv.cvtColor(testMat,cv.COLOR_BGR2GRAY);
console.log(testMat.shape,grey.shape)
console.time("Contours")
const contours = cv.findContours(grey,cv.RETR_EXTERNAL,cv.CHAIN_APPROX_SIMPLE)
const idx = 20
const epsilon = 0.006 * cv.arcLength(contours[idx],true)

const approx = cv.approxPolyDp(contours[idx],epsilon,true)
console.timeEnd("Contours")
console.log(grey.clone().toArray())
console.log(approx.length,contours[idx].length)
cv.imwrite(
  cv.resize(testMat, [testMat.shape[1] * 0.2, testMat.shape[2] * 0.2], cv.INTER_AREA),
  "./result.png"
);
