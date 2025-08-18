const express = require('express');
const app = express();
const port = 3050;

app.use((req, res, next) => {
    console.log(`[Middleware 1] Incoming ${req.method} request to ${req.url}`);
    next();
});
app.use((req, res, next) => {
    res.setHeader('X-Processed-By-Middleware', 'True');
    console.log(`[Middleware 2] Added custom header`);
    next();
});

app.get('/',(req,res)=>{
    console.log('[Route Handler] Sending response.');
    res.send('Hello from the main route! Check the console for middleware logs and your browser\'s network tab for the custom header.');
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});
