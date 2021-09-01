const path = require('path');

const ADLConfig = {
  entry: './public/javascripts/index.webpack.js',
  mode: 'production',
  output: {
    filename: 'adl.min.js',
    path: path.resolve(__dirname, 'public', 'javascripts'),
  },
};

ADLPublicConfig = ADLConfig

ADLDistConfig = JSON.parse(JSON.stringify(ADLConfig))
ADLDistConfig.output.path = path.resolve(__dirname, 'dist')

module.exports = [ADLConfig, ADLDistConfig]