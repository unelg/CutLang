#! /usr/bin/env node

var sgMail = require('@sendgrid/mail');
sgMail.setApiKey(process.env.SENDGRID_API_KEY);

var fs = require('fs')

var _version = fs.readFileSync('./VERSION');

var msg = {
    to: ['tobuba2@gmail.com'],
    from: 'tobuba2@gmail.com',
    subject: 'CutLang Package Report - Conda, Macos, Success v'+_version,
    text: 'Built successfully and uploaded new conda package. New conda package '+_version+' is available',
};

sgMail
    .send(msg)
    .then(() => console.log('Mail sent successfully'))
    .catch(error => console.error(error.toString()));
