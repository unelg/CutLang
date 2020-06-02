#! /usr/bin/env node

const sgMail = require('@sendgrid/mail');
sgMail.setApiKey(process.env.SENDGRID_API_KEY);

const fs = require('fs'),
    filename = 'errors.txt',
    fileType = 'plain/text',
    data = fs.readFileSync('./.github/workflows/artifacts/' + filename);

const error_message = fs.readFileSync('./.github/workflows/artifacts/temp.txt', 'utf8')

const msg = {
    to: ['Gokhan.Unel@gmail.com','ssekmen@gmail.com','arponpaul1995@gmail.com','jinens8@gmail.com'],
    from: 'jinens8@gmail.com',
    subject: 'CutLang Build Report',
    text: 'Built successfully but run errors reported. Output file as attached.\nErrors:\n'+error_message+'\nError context in attached document.',
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
