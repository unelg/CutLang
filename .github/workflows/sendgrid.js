#! /usr/bin/env node

const sgMail = require('@sendgrid/mail');
sgMail.setApiKey(process.env.SENDGRID_API_KEY);

const fs = require('fs'),
    filename = 'errors.txt',
    fileType = 'plain/text',
    data = fs.readFileSync('./.github/workflows/artifacts/' + filename),

    filename_raw_output = 'raw_output.txt',
    fileType_raw_output = 'plain/text',
    data_raw_output = fs.readFileSync('./.github/workflows/artifacts/' + filename_raw_output),

    filename_efficacy_charts = 'efficacy_charts.txt',
    fileType_efficacy_charts = 'plain/text',
    data_efficacy_charts = fs.readFileSync('./.github/workflows/artifacts/' + filename_efficacy_charts),

    filename_differences = 'differences.txt',
    fileType_differences = 'plain/text',
    data_differences = fs.readFileSync('./.github/workflows/artifacts/' + filename_differences);

const error_message = fs.readFileSync('./.github/workflows/artifacts/errors.txt', 'utf8')

const msg = {
    to: ['gokhan.unel@gmail.com','ssekmen@gmail.com','tobuba2@gmail.com'],
    from: 'gokhan.unel@cern.ch',
    subject: 'CutLang Build Report',
    text: 'Built successfully but run errors reported. Output file as attached.\nErrors:\n'+error_message+'\nError context in attached document.',
    attachments: [
        {
            content: data.toString('base64'),
            filename: filename,
            type: fileType,
            disposition: 'attachment',
        },
        {
            content: data_raw_output.toString('base64'),
            filename: filename_raw_output,
            type: fileType_raw_output,
            disposition: 'attachment',
        },
        {
            content: data_efficacy_charts.toString('base64'),
            filename: filename_efficacy_charts,
            type: fileType_efficacy_charts,
            disposition: 'attachment',
        },
        {
            content: data_differences.toString('base64'),
            filename: filename_differences,
            type: fileType_differences,
            disposition: 'attachment',
        },
    ],
};

sgMail
    .send(msg)
    .then(() => console.log('Mail sent successfully'))
    .catch(error => console.error(error.toString()));
