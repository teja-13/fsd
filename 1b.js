const express = require('express');
const app = express();
const port = 3050;

app.use(express.json());
let datastore = [];
let idcounter = 1;
app.post('/resource', (req, res) => {
  const {name,value} = req.body;
  if(!name || !value) {
    return res.status(400).send('Name and value are required');
  }
  const newitem = {id: idcounter++, name, value};
  datastore.push(newitem);
  res.status(201).json({message: 'Resource created', resource: newitem});
});

app.get('/resource', (req, res) => {
    res.status(200).json(datastore);
});

app.delete('/resource/:id', (req, res) => {
  const id = parseInt(req.params.id, 10);
  const index = datastore.findIndex(item => item.id === id);
  if (index === -1) {
    return res.status(404).send('Resource not found');
  }
  const deleteditem = datastore.splice(index, 1);
  res.status(200).json({message: 'Resource deleted', resource: deleteditem[0]});
});
app.listen(port, () => {
  console.log(`Server running at http://localhost:${port}`);
}   );


//curl -X POST http://localhost:3050/resource -H "Content-Type: application/json" -d "{\"name\":\"Test\", \"value\":\"123\"}"
//curl -X GET http://localhost:3050/resource
//curl -X DELETE http://localhost:3050/resource/1