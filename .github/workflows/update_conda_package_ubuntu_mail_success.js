#! /usr/bin/env node

var sgMail = require('@sendgrid/mail');
sgMail.setApiKey(process.env.SENDGRID_API_KEY);

var fs = require('fs')

var _version = fs.readFileSync('./VERSION');

var msg = {
    to: ['gokhan.unel@cern.ch','ssekmen@gmail.com','arponpaul1995@gmail.com','jinens8@gmail.com','tobuba2@gmail.com'],
    from: 'gokhan.unel@cern.ch',
    subject: 'CutLang Package Report - Conda, Ubuntu, Success v'+ _version,
    text: 'Built successfully and uploaded new conda package. New conda package '+_version+' is available',
};

sgMail
    .send(msg)
    .then(() => console.log('Mail sent successfully'))
    .catch(error => console.error(error.toString()));
