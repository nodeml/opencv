"use strict";
const opencv = require("bindings")("nodeml_opencv");

module.exports = { ...opencv };
