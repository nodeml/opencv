const cv = require("./lib");

const testMat = cv.imread("./img.png");
console.log(
  "OH YEAH",
  testMat,
  testMat.shape,
  cv.resize(testMat, [testMat.shape[0] * 0.2, testMat.shape[1] * 0.2], "cubic")
    .shape
);
cv.imwrite(
  cv.resize(testMat, [testMat.shape[0] * 0.2, testMat.shape[1] * 0.2], "area"),
  "./result.png"
);
