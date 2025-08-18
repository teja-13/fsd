const express = require('express');
const app = express();

app.get('/', (req, res) => {
  res.setHeader('Content-Type', 'text/html');
  res.setHeader('X-Custom-Header', 'Hello from Node.js');
  res.send('<h1>Hello World!</h1>');
});

app.listen(3000, () => {
  console.log('Server listening on port 3000');
});