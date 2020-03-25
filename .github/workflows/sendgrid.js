#! /usr/bin/env node

const sgMail = require('@sendgrid/mail');
sgMail.setApiKey(process.env.SENDGRID_API_KEY);

const fs = require('fs'),
    filename = 'artifacts.zip',
    fileType = 'application/zip',
    data = fs.readFileSync('./.github/previous/' + filename);

const msg = {
    to: ['Gokhan.Unel@cern.ch','arponpaul1995@gmail.com','jinens8@gmail.com'],
    from: 'jinens8@gmail.com',
    subject: 'CutLang Build Report',
    text: 'Built successfully but run errors reported. Output file as attached.',
    attachments: [
        {
            content: data.toString('base64'),
            filename: filename,
            type: fileType,
            disposition: 'attachment',
        },
    ],
};

sgMail
    .send(msg)
    .then(() => console.log('Mail sent successfully'))
    .catch(error => console.error(error.toString()));
