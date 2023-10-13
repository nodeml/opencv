export declare class Mat {
  shape: [number, number];
}

export declare function imread(path: string): Mat;

export declare function imwrite(mat: Mat, path: string): Boolean;

export declare function resize(
  mat: Mat,
  dSize: [number, number],
  mode: "linear" | "area" | "cubic" = "linear"
);
