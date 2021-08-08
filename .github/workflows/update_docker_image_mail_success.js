#! /usr/bin/env node

const sgMail = require('@sendgrid/mail');
sgMail.setApiKey(process.env.SENDGRID_API_KEY);

const fs = require('fs'),

const version = data = fs.readFileSync('./VERSION');

const msg = {
    to: ['tobuba2@gmail.com'],
    from: 'tobuba2@gmail.com',
    subject: 'CutLang Image Report - Docker, Success v' + version,
    text: 'Built successfully and uploaded new image package. New image package '+version+' is available',
};

sgMail
    .send(msg)
    .then(() => console.log('Mail sent successfully'))
    .catch(error => console.error(error.toString()));
